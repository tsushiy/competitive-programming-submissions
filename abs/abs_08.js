"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let ny = input[0].split(" ");
  let n = parseInt(ny[0]);
  let y = parseInt(ny[1]);

  let ok = false;
  for (let i = 0; i <= n; ++i) {
    for (let j = 0; j <= n; ++j) {
      let rem = y - 10000*i - 5000*j;
      if (rem >= 0 && rem / 1000 == n-i-j) {
        return [i, j, n-i-j].join(" ");
      }
    }
  }

  return [-1, -1, -1].join(" ");
}