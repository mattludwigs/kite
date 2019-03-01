type method =
  | GET
  | POST
  | INVALID;

type path = string;

type t = {
  method,
  path,
  body: string,
};

let method_of_string = meth => {
  switch (meth) {
  | "GET" => GET
  | "POST" => POST
  | _ => INVALID
  };
};

let path = req => req.path;
let body = req => req.body;

let from_raw = (cohttprequest, body) => {
  let meth =
    cohttprequest |> Cohttp.Request.meth |> Cohttp.Code.string_of_method;
  let path = cohttprequest |> Cohttp.Request.uri |> Uri.path;

  {method: method_of_string(meth), path, body};
};