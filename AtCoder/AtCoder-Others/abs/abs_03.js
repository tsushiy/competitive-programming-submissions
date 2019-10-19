"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let n = parseInt(input[0]);
  let a = input[1].split(" ").map(a=>parseInt(a));

  let ans = 1<<30;
  for (let i = 0; i < n; ++i) {
    let cnt = 0;
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      ++cnt;
    }
    ans = Math.min(ans, cnt);
  }

  return ans;
}