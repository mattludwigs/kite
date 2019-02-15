open Lwt;
open Cohttp;
open Cohttp_lwt_unix;

let handle_bob = (_conn, req, _body) => {
  Server.respond_string(~status=`OK, ~body="Bob", ());
};

let handle_default = (_conn, req, body) => {
  let uri = req |> Request.uri |> Uri.to_string;
  let meth = req |> Request.meth |> Code.string_of_method;
  let headers = req |> Request.headers |> Header.to_string;

  body
  |> Cohttp_lwt.Body.to_string
  >|= (
    body =>
      Printf.sprintf(
        "Uri: %s\nMethod: %s\nHeaders\nHeaders: %s\nBody: %s\n",
        uri,
        meth,
        headers,
        body,
      )
  )
  >>= (body => Server.respond_string(~status=`OK, ~body, ()));
};

let server = () => {
  let callback = (conn, req, body) => {
    let path = req |> Request.uri |> Uri.path;

    switch (path) {
    | "/bob" => handle_bob(conn, req, body)
    | _ => handle_default(conn, req, body)
    };
  };

  let makeServer = () => {
    Server.make(~callback, ());
  };

  Server.create(~mode=`TCP(`Port(8000)), makeServer());
};

let _ = ignore @@ Lwt_main.run(server());