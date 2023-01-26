const creds = require("./creds.json"); //cred information
const { Client } = require("pg");
const client = new Client({
    host: '3380db.cs.uh.edu',
    user: 'dbs043',
    password: '1833106H',
    port: 5432,
    database: 'COSC3380'
});
const fs = require("fs"); //writing to file
const filename = "nf.txt"; // filename is called nf.sql
const filesql = "nf.sql"; // filename is called nf.sql



//global variables
var tableName = "";
var arraykey = "";
var arrcol = "";
var allCols;
var arrcandidate;
var validpk = true;
var boolnf1 = false;
var boolnf2 = false;
var boolnf3 = false;
var boolBCNF = false;
var pk;
var funcArr = [];
var funcMap = new Map();

//var result= await client.query("SELECT "+ columnA+", COUNT(DISTINCT "+columnB+") FROM "+ tableName + " GROUP BY " + columnA + " HAVING COUNT(DISTINCT "+ columnB+") > 1;");
//Used https://www.youtube.com/watch?v=ufdHsFClAk0&ab_channel=HusseinNasser as guidance
async function main() {
    try {
        //connect to client
        await client.connect();
        /*
        if (fs.existsSync(filesql)){
            fs.truncate(filesql, 0, function () {
                //console.log('Cleaned')
            })
        }
        */
        //parse cmd information
        parse();
        //checks if pk is valid
        checkpk()
        //fetches unique pks
        uniquepks = 0;
        totrows = null;
        await countrows();
        await countuniquepks();
        await checkcandidate();
        //compares if it has validpk and if uniquepks are not equal to total rows
        //console.log(uniquepks)
        //console.log(totrows)
        if (uniquepks < totrows) {
            validpk = false;
            //console.log(validpk)
        }
        //checks for nf1
        await checknf1();
        //checks for nf2
        await checknf2();
        if (validpk != true && boolnf1 != true) {
            boolnf2 = false
        }
        //checks for 
        await checknf3();
        if (validpk != true && boolnf2 != true) {
            boolnf3 = false
        }
        //checks for bcnf
        await checkBCNF();
        if (validpk != true && boolnf3 != true) {
            boolbcnf = false
        }
        //clears file text
        /*
        if (fs.existsSync(filename)) {
            fs.truncate(filename, 0, function () {
                //console.log('Cleaned')
            })
        }
        */
        await appendDataToFile(filename,
            tableName + "\n")
            .catch(err => {
                console.log(err)
            })
        //write to txt file
        await writeFile();
        client.end();

        // Release resources...
    } catch (err) { console.error(err); }
    finally { await client.end(); console.log("Connection closed.") }
}

async function parse() {
    try {
        //cmd input
        params = process.argv[2];
        //stops if no parameters
        if (process.argv.length != 3) {
            invalidinput();
        }
        //split by ;
        else {
            l = params.split(";")
            param = [];
            if (l.length != 3) {
                invalidinput();
            }
            //stores split strings into param array
            for (i = 0; i < l.length; i++)
                param[i] = l[i].split("=");
            //extracts string variables based on name
            for (var i = 0; i < param.length; i++) {
                if (param[i][0] == 'table') {
                    tableName = param[i][1];
                }
                if (param[i][0] == 'pk') {
                    pks = param[i][1];
                }
                if (param[i][0] == 'columns') {
                    columns = param[i][1];
                }
            }
            if ((typeof tableName === 'undefined') || (typeof pks === 'undefined') || (typeof columns === 'undefined') || (tableName.length == 0) || (pks.length == 0) || (columns.length == 0)) {
                invalidinput();
            }
            //converts string to array
            arraykey = pks.split(',');
            arrcol = columns.split(',');
        }
    } catch (error) { console.error("invalid input"); }
}

async function checkpk() {
    for (var i = 0; i < arraykey.length; i++) {
        for (var j = 0; j < arrcol.length; j++) {
            if (arraykey[i] == arrcol[j]) {
                validpk = false;
            }
        }
    }
    //pk is at max 2
    if (validpk && arraykey.length > 2) {
        invalidinput();
    }
    if (arraykey.length == 2) {
        pk = arraykey[0] + "," + arraykey[1];
    }
    else {
        pk = arraykey[0];
    }
    try {
        if (arraykey.length == 2) {
            var result = await client.query("/*checking if pk is null*/" + "\n" + "SELECT COUNT(*) FROM " + tableName + " where " + arraykey[0] + " is null OR " + arraykey[1] + " is null;");
            writesql("/*checking if pk is null*/" + "\n" + "SELECT COUNT(*) FROM " + tableName + " where " + arraykey[0] + " is null OR " + arraykey[1] + " is null;");
        }
        else {
            var result = await client.query("/*checking if pk is null*/" + "\n" + "SELECT COUNT(*) FROM " + tableName + " where " + arraykey[0] + " is null;");
            writesql("/*checking if pk is null*/" + "\n" + "SELECT COUNT(*) FROM " + tableName + " where " + arraykey[0] + " is null;");
        }
        
        nullpk = result.rows[0].count;
        if (nullpk != 0) {
            validpk = false;
        }
    } catch (error) { console.error(error); }
}

/*
 console.log("Before Error")
        console.log("pk=" + arraykey)
        console.log("tableName=" + tableName)
        var result = await client.query("SELECT COUNT(*) FROM (SELECT DISTINCT " + pk + " FROM " + tableName + ") AS t;");
        console.log("After Error")
 */
//"SELECT COL_LENGTH('" + tableName + "','" + arrcol[i] + "') IS NOT NULL"
async function countuniquepks() {
    try {
        var result = await client.query("SELECT COUNT(*) FROM (SELECT DISTINCT " + pk + " FROM " + tableName + ") AS t;");
        writesql("/*counting unique pks*/" + "\n" + "SELECT COUNT(*) FROM (SELECT DISTINCT " + pk + " FROM " + tableName + ") AS t;");
        uniquepks = result.rows[0].count;
    } catch (error) { console.error(error); }
}
async function countrows() {
    var result = await client.query(`SELECT COUNT(*) FROM ${tableName};`);
    writesql("/*counting total rows*/" + "\n" + `SELECT COUNT(*) FROM ${tableName};`);
    totrows = result.rows[0].count;
    allCols = arraykey.concat(arrcol); //
    allCols = new Set(allCols); //makes it with a new set and removes duplicates
    allCols = Array.from(allCols);
    for (var i = 0; i < allCols.length; i++) {
        var result = await client.query("SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '" + tableName + "' AND COLUMN_NAME = '" + allCols[i]+"'");
        writesql("SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '" + tableName + "' AND COLUMN_NAME = '" + allCols[i] + "'");
        if (result.rows[0].count == 0) {
            invalidinput();
        }

    }
    if (totrows == 0) {
        if (fs.existsSync(filename)) {
            fs.truncate(filename, 0, function () {
                //console.log('Cleaned')
            })
        }
        await appendDataToFile(filename,
            "Empty Table")
            .catch(err => {
                console.log(err)
            })
        process.exit(0);
    }
    if (totrows == 1) {
        if (fs.existsSync(filename)) {
            fs.truncate(filename, 0, function () {
                //console.log('Cleaned')
            })
        }
        await appendDataToFile(filename,
            "Single Row Table")
            .catch(err => {
                console.log(err)
            })
        process.exit(0);
    }
}
//var result = await client.query("select (count(*) <> count(" + pk+ ")) FROM " + tableName +";");
//await client.query("SELECT COUNT(*) FROM " + tableName + " GROUP BY "+arraykey+";");
//SELECT COUNT(*) FROM (SELECT k1 FROM hw2_1nf_2nf_1 GROUP BY k1,k2,b) AS t;
async function checknf1() {
    try {
        var result = await client.query("SELECT COUNT(*) FROM (SELECT " + pk + " FROM " + tableName + " GROUP BY " + arraykey + "," + arrcol + ") AS t;");
        writesql("/*check nf1*/" + "\n" + "SELECT COUNT(*) FROM (SELECT " + pk + " FROM " + tableName + " GROUP BY " + arraykey + "," + arrcol + ") AS t;");
        if (totrows == result.rows[0].count) {
            boolnf1 = true;
        }
    } catch (error) { console.error(error); }
}
async function checknf2() {
    try {
        await checkfunc()
        if (arraykey.length == 1) {//the pk is one attribute
            if (validpk && boolnf1 == true) {
                boolnf2 = true;
            }
        }
        else {//the pk is composite
            var boolpartial = true;
            for (i = 0; i < funcArr.length; i++) {
                if ((((pk.indexOf(funcArr[i][0]) !== -1) && (pk.indexOf(funcArr[i][1]) == -1)))) {
                    boolpartial = false;
                }
            }
            if (boolpartial) {
                if (validpk && (boolnf1 == true)) {
                    boolnf2 = true;
                }
            }
        }
    } catch (error) { console.error(error); }
}
//||((funcArr[i][0]!=pk&&(funcArr[i][1]==pk))
/*
checkpartialfunc(){}
var result = await client.query(`SELECT COUNT(DISTINCT ${columnB}) FROM ${tableName} GROUP BY ${columnA} HAVING COUNT(DISTINCT ${columnB}) > 1;`);
'SELECT a, COUNT(DISTINCT b) FROM table GROUP BY a HAVING COUNT(DISTINCT b) > 1;'

*/
async function checkfunc() {
    try {
        for (let i = 0; i < allCols.length; i++) {
            for (let j = 0; j < allCols.length; j++) {
                //ignore the same column
                if (i != j) {
                    var columnA = allCols[i];
                    var columnB = allCols[j];
                    var result = await client.query("SELECT " + columnA + ", COUNT(DISTINCT " + columnB + ") FROM " + tableName + " GROUP BY " + columnA + " HAVING COUNT(DISTINCT " + columnB + ") > 1;");
                    writesql("/*check func between*/" + columnA + " and " + columnB + "\n" + "SELECT " + columnA + ", COUNT(DISTINCT " + columnB + ") FROM " + tableName + " GROUP BY " + columnA + " HAVING COUNT(DISTINCT " + columnB + ") > 1;");
                    //not true if result is empty
                    if (result.rows.length) {
                        continue;
                    }
                    //remove duplicates
                    if (funcMap.has(columnB) && funcMap.get(columnB).includes(columnA)) {
                        continue;
                    }
                    //if a unique functional dependency is found, store it.
                    if (!funcMap.has(columnA))
                        funcMap.set(columnA, []);
                    funcMap.get(columnA).push(columnB);
                    funcArr.push([columnA, columnB]);
                }
            }
        }
        /*
        for (i = 0; i < funcArr.length; i++) {
            console.log(funcArr[i])
        }
        */
        
    } catch (error) { console.error(error); }
}
/*
        console.log(arrcol[i])
        console.log(result.rows[0].count)
        console.log(totrows)
        */
async function checkcandidate() {
    try {
        for (let i = 0; i < arrcol.length; i++) {
            var result = await client.query("SELECT COUNT(*) FROM (SELECT DISTINCT " + arrcol[i] + " FROM " + tableName + ") AS t;");
            writesql("/*counting unique pks*/" + "\n" + "SELECT COUNT(*) FROM (SELECT DISTINCT " + arrcol[i] + " FROM " + tableName + ") AS t;");
            if (result.rows[0].count==totrows) {
                arrcandidate.push(arrcol[i]);
            }
        }
    } catch (error) { console.error(error); }
}
//if (((funcArr[i][0].indexOf(pk) !== -1) && (funcArr[i][1].indexOf(pk) !== -1))) {
async function checknf3() {
    try {
        var booltransitive = true;
        for (i = 0; i < funcArr.length; i++) {
            //console.log(pk.indexOf(funcArr[i][0]))
            if (((pk.indexOf(funcArr[i][0]) == -1) && (pk.indexOf(funcArr[i][1]) == -1))) {
                booltransitive = false;
            }
        }
        if (booltransitive) {
            if (validpk && boolnf2 == true) {
                boolnf3 = true;
            }
        }
    } catch (error) { console.error(error); }
}
async function checkBCNF() {
    try {
        var boolrelation = true;
        //console.log(pk.indexOf(funcArr[i][1]))
        for (i = 0; i < funcArr.length; i++) {
            if ((pk.indexOf(funcArr[i][0]) == -1) && (pk.indexOf(funcArr[i][1]) !== -1)) {
                boolrelation = false;
            }
        }
        if (validpk && boolrelation) {
            if (boolnf3 == true) {
                boolBCNF = true;
            }
        }
    } catch (error) { console.error(error); }
}

async function writeFile() {
    boolarr = [validpk, boolnf1, boolnf2, boolnf3, boolBCNF];
    namesarr = ["PK", "1NF", "2NF", "3NF", "BCNF"];
    outputarr = [];
    output = "N";
    for (i = 0; i < namesarr.length; i++) {
        if (boolarr[i]) {
            output = "Y";
        }
        else {
            output = "N";
        }
        outputarr.push(output);
        console.log(output)
    }
    /*await fs.appendFile(filename, namesarr[i].padEnd(5) + outputarr[i]+"\n", (err) => {
        if(err) 
        throw err;
    });
    */
    for (i = 0; i < namesarr.length; i++) {
        await appendDataToFile(filename,
            namesarr[i].padEnd(5) + outputarr[i] + "\n")
            .catch(err => {
                console.log(err)
            })

    }
}
const appendDataToFile = async (filename, data) => {
    await fs.promises.appendFile(filename, data, (err) => {
        if (err)
            throw err;
    });
}

async function writesql(str) {
    fs.appendFile(filesql, str + "\n", function (err) {
        if (err) throw err;
        //console.log('Saved!');  
    });
}
async function invalidinput() {
    if (fs.existsSync(filename)) {
        fs.truncate(filename, 0, function () {
            //console.log('Cleaned')
        })
    }
    await appendDataToFile(filename,
        "Invalid input")
        .catch(err => {
            console.log(err)
        })
    process.exit(0);
}
/*
fs.appendFile(filename, namesarr[i].padEnd(5) + outputarr[i]+"\n", (err) => {
if(err) 
 throw err;
console.log('The new_content was appended successfully');
});
*/
main();

