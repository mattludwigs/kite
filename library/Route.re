open Cohttp;

type t = {
  method: Code.meth,
  path: string,
  handler: Handle.t,
};

let make = (method, path, handler) => {
  {method, path, handler};
};

let isMatch = (route, path) => String.compare(route.path, path);

let getHandle = route => route.handler;