"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let s = input[0];

  let ans = 0;
  for (let i = 0; i < 3; ++i) {
    if (s[i] == "1") ++ans;
  }

  return ans;
}