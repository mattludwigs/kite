module Std = Std;

type t;

let empty: unit => t;

let get: (string, Handle.t, t) => t;

let post: (string, Handle.t, t) => t;

let listen: t => unit;