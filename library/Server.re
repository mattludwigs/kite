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

let getHandleForRequest = (req, server) => {
  let path = Request.path(req);

  Router.getHandleForPath(path, server.router);
};

let listen = server => {
  let mode = tcpMode(getPort(server));
  Console.log(server.port);
  let callback = (_, req, _) => {
    let req = Request.from_raw(req);
    let res = getHandleForRequest(req, server) @@ req;
    Response.send(res);
  };
  ignore @@
  Lwt_main.run(CoServer.create(~mode, CoServer.make(~callback, ())));
};