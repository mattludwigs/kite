open Lwt;

module Std = Std;
module CoServer = Cohttp_lwt_unix.Server;

type port = int;

type t = {
  port,
  router: Router.t,
};

type handler = Request.t => Response.t;

let empty = () => {
  {port: 3000, router: Router.empty()};
};

let getPort = server => server.port;

let setPort = (server, port) => {
  port;
};

let get = (path, handler, server) => {
  let route = Route.make(`GET, path, handler);

  {...server, router: Router.putRoute(route, server.router)};
};

let tcpMode = port => `TCP(`Port(port));

let listenWith = (handler, server) => {
  let mode = tcpMode(getPort(server));

  let callback = (_, req, _) => {
    let req = Request.from_raw(req);
    let promise = handler(req);
    Response.send(promise);
  };

  ignore @@
  Lwt_main.run(CoServer.create(~mode, CoServer.make(~callback, ())));
};

let listen = server => {
  ignore @@ listenWith(Handle.empty, server);
};