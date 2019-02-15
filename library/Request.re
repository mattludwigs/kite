open Cohttp;

type method =
  | GET
  | INVALID;

type t = {method};

let method_of_string = meth => {
  switch (meth) {
  | "GET" => GET
  | _ => INVALID
  };
};

let from_raw = cohttprequest => {
  let meth = cohttprequest |> Request.meth |> Code.string_of_method;

  {method: method_of_string(meth)};
};