open Server.Std;

let _ =
  Server.empty()
  |> Server.get("/", _req => Handle.render_text("Hello world"))
  |> Server.listen;