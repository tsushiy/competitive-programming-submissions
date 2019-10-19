"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let n = parseInt(input[0]);
  let TXY = input.slice(1);

  let ok = true;
  let t = 0;
  let x = 0;
  let y = 0;

  for (let i = 0; i < n; ++i) {
    let txy = TXY[i].split(" ").map(n=>parseInt(n));
    let d = Math.abs(txy[1] - x) + Math.abs(txy[2] - y);
    if (!((txy[0] - t) >= d && ((txy[0] - t) - d) % 2 == 0)) ok = false;
  }

  if (ok) return "Yes";
  else return "No";
}