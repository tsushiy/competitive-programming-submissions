"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let n = parseInt(input[0]);
  let a = input[1].split(" ").map(a=>parseInt(a));
  a.sort(function(a, b) { return b-a; });

  let alice = 0;
  let bob = 0;
  for (let i = 0; i < n; i += 2) alice += a[i];
  for (let i = 1; i < n; i += 2) bob += a[i];

  return alice - bob;
}