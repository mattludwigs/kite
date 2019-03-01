open Lwt;
open Kite;
open Kite.Std;

let postHandler = req => {
  let resStr = Printf.sprintf("POSTED: %s", Request.body(req));
  Handle.render_text(resStr);
};

let _ =
  Server.empty()
  |> Server.get("/", _req => Handle.render_text("Hellooooo world"))
  |> Server.post("/post-route", postHandler)
  |> Server.listen;