function calcWordFrequencies() {

   var words = prompt("Enter the sentence below").split(" ");

   var unique_words = [], freqencies = [], count = 0;

   for (var i = 0; i < words.length; i++) {

       var found = false;

       for (var j = 0; j < count; j++) {

           if (words[i] === unique_words[j]) {

               freqencies[j] = freqencies[j] + 1;

               found = true;

           }

       }

       if (!found) {

           unique_words[count] = words[i];

           freqencies[count] = 1;

           count++;

       }

   }

   for (var i = 0; i < words.length; i++) {

       var result = 0;

       for (var j = 0; j < count; j++) {

           if (words[i] === unique_words[j]) {

               result = freqencies[j];

               break;

           }

       }

       console.log(words[i] + " " + result);

   }

}