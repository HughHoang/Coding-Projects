function divideArray(a){
    let even_list = [];
    let odd_list = [];
    for (let i = 0; i < a.length; i++) {
        if (a[i] % 2 == 0) { even_list.push(a[i]); }
        else { odd_list.push(a[i]); }
    }
    even_list.sort(function (a1, a2) { return a1 - a2 })
    odd_list.sort(function (a1, a2) { return a1 - a2 })
    console.log("Even numbers:");
    if (even_list.length == 0) { console.log("None"); }
    else {
        for (let i = 0; i < even_list.length; i++)
        { console.log(even_list[i]); }
    }
    console.log("Odd numbers:");
    if (odd_list.length == 0) { console.log("None"); }
    else { for (let i = 0; i < odd_list.length; i++) { console.log(odd_list[i]); } }
} 