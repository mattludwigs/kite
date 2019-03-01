open Kite;

let postHandler = req => {
  let resStr = Printf.sprintf("POSTED: %s", Request.body(req));
  Response.renderText(resStr);
};

let _ =
  Server.empty()
  |> Server.get("/", _req => Response.renderText("Hellooooo world"))
  |> Server.post("/post-route", postHandler)
  |> Server.listen;