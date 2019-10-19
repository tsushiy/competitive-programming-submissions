"use strict";
console.log(main(require("fs").readFileSync("/dev/stdin", "utf8")));

function main(args) {
  const input = args.trim().split("\n");

  let s = input[0].split("").reverse().join("");
  let ok = true;

  let pos = 0;
  while (pos != s.length) {
    let t = s.slice(pos, pos+5);
    if (t == "maerd" || t == "esare") pos += 5;
    else if (s.slice(pos, pos+6) == "resare") pos += 6;
    else if (s.slice(pos, pos+7) == "remaerd") pos += 7;
    else {
      ok = false;
      break;
    }
  }

  if (ok) return "YES";
  else return "NO";
}