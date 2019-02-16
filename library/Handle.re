type t = Request.t => Response.t;

let empty = _req => {
  Response.empty();
};

let render_text = text => {
  Response.empty() |> Response.putBody(`String(text));
};