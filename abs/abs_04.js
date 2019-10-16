"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let a = parseInt(input[0]);
  let b = parseInt(input[1]);
  let c = parseInt(input[2]);
  let x = parseInt(input[3]);

  let ans = 0;
  for (let i = 0; i <= a; ++i) {
    for (let j = 0; j <= b; ++j) {
      for (let k = 0; k <= c; ++k) {
        if (500*i + 100*j + 50*k == x) ++ans;
      }
    }
  }

  return ans;
}