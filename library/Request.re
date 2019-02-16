type method =
  | GET
  | INVALID;

type path = string;

type t = {
  method,
  path,
};

let method_of_string = meth => {
  switch (meth) {
  | "GET" => GET
  | _ => INVALID
  };
};

let path = req => req.path;

let from_raw = cohttprequest => {
  let meth =
    cohttprequest |> Cohttp.Request.meth |> Cohttp.Code.string_of_method;
  let path = cohttprequest |> Cohttp.Request.uri |> Uri.path;

  {method: method_of_string(meth), path};
};