/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currentCount = init;
    return {
        increment: () => ++currentCount,
        decrement: () => --currentCount,
        reset: () => (currentCount = init),
    }
    
};

// var createCounter = function(init) {
//   let currentCount = init;
//   return new Proxy({}, {
//     get: (target, key) => {
//       switch(key) {
//         case "increment":
//           return () => ++currentCount;
//         case "decrement":
//           return () => --currentCount;
//         case "reset":
//           return () => (currentCount = init);
//         default:
//           throw Error("Unexpected Method")
//       }
//     },
//   });
// };
/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */