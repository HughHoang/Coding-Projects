function calcWordFrequencies() {
var wordmap = new Map();
   var words = prompt("Enter the sentence below").split(" ");
    var freqMap = {};
    words.forEach(function(w) {
        if (!freqMap[w]) {
            freqMap[w] = 0;
        }
        freqMap[w] += 1;
    });

Object.keys(freqMap).forEach(function(word) {
    console.log(word +" " + freqMap[word]);
});
}