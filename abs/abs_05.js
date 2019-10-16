"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let nab = input[0].split(" ");
  let n = parseInt(nab[0]);
  let a = parseInt(nab[1]);
  let b = parseInt(nab[2]);

  let ans = 0;
  for (let i = 1; i <= n; ++i) {
    let cur = i;
    let cnt = 0;
    while (cur > 0) {
      cnt += cur % 10;
      cur = Math.floor(cur / 10);
    }
    if (a <= cnt && cnt <= b) ans += i;
  }

  return ans;
}