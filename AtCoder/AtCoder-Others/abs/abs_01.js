"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let a = parseInt(input[0].split(" ")[0]);
  let b = parseInt(input[0].split(" ")[1]);

  if (a * b % 2 == 0) return "Even";
  else return "Odd";
}