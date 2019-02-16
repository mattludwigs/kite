open Cohttp;

type t = {
  method: Code.meth,
  path: string,
  handler: Handle.t,
};

let make = (method, path, handler) => {
  {method, path, handler};
};