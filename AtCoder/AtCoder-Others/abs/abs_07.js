"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let n = parseInt(input[0]);
  let d = input.slice(1).map(n=>parseInt(n)).sort((a, b)=>b-a);

  let ans = 1;
  for (let i = 1; i < n; ++i) {
    if (d[i] < d[i-1]) ++ans;
    else if (d[i] == d[i-1]) continue;
    else break;
  }

  return ans;
}