"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let a = parseInt(input[0]);
  let b = parseInt(input[1].split(" ")[0]);
  let c = parseInt(input[1].split(" ")[1]);
  let s = input[2];

  let ans = [];
  ans.push(a+b+c);
  ans.push(s);

  return ans.join(" ");
}