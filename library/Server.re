open Cohttp;
open Lwt;

module Html = Html;
module Server = Cohttp_lwt_unix.Server;

type port = int;

type t = {port};

type handler = Request.t => Response.t;

let empty = () => {
  {port: 3000};
};

let getPort = server => server.port;

let setPort = (server, port) => {
  port;
};

let tcpMode = port => `TCP(`Port(port));

let statusOk = `OK;

let respond = (body, status) => {
  Server.respond(~status=statusOk, ~body=`Empty, ());
};

let root = (_conn, req, body) => {
  respond(`Empty, statusOk);
};

let listen = server => {
  let mode = tcpMode(getPort(server));
  ignore @@
  Lwt_main.run(Server.create(~mode, Server.make(~callback=root, ())));
};

let listWith = (server, callback) => {
  let mode = tcpMode(getPort(server));

  ignore @@ Lwt_main.run(Server.create(~mode, Server.make(~callback, ())));
};