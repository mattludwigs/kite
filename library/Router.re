type t = {routes: list(Route.t)};

let empty = () => {
  {routes: []};
};

let putRoute = (route, router) => {
  {routes: router.routes @ [route]};
};

let getHandleForPath = (path, router) => {
  router.routes
  |> List.find(route => Route.isMatch(route, path) == 0)
  |> Route.getHandle;
};