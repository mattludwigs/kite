open Lwt;
open Server.Std;

let myLongHandler = _req => {
  Unix.sleep(10);
  Handle.render_text("Hello");
};

let postHandler = req => {
  Handle.render_text("POST!");
};

let _ =
  Server.empty()
  |> Server.get("/", _req => Handle.render_text("Hello world"))
  |> Server.get("/long", myLongHandler)
  |> Server.post("/post-route", postHandler)
  |> Server.listen;