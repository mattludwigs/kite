type t = {routes: list(Route.t)};

let empty = () => {
  {routes: []};
};

let putRoute = (route, router) => {
  {routes: router.routes @ [route]};
};