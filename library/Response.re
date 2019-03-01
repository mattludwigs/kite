open Cohttp;

module Server = Cohttp_lwt_unix.Server;

type body = Cohttp_lwt.Body.t;

type statusCode = Code.status_code;

type t = {
  statusCode,
  body,
};

let empty = () => {
  {body: `Empty, statusCode: `OK};
};

let putBody = (body, req) => {
  {...req, body};
};

let statusCode = (statusCode, req) => {
  {...req, statusCode};
};

let send = res => {
  Server.respond(~status=res.statusCode, ~body=res.body, ());
};

let renderText = text => {
  empty() |> putBody(`String(text));
};