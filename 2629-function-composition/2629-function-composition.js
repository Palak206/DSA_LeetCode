/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        if (functions.length === 0) {
            return x;
        } 
        else {
           var result = x;
           for (var i = functions.length - 1; i >= 0; i--) {
             result = functions[i](result);
           }
      return result;
    }

    }
};

// var compose = function(functions) {
//   return function(x) {
//     return functions.reduceRight(function(acc, fn) {
//       return fn(acc);
//     }, x);
//   }
// };

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */