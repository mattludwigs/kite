type htmlNode =
  | P
  | Text;

type t = {
  node: htmlNode,
  value: option(string),
  children: list(t),
};

let text = text => {
  {node: Text, value: text, children: []};
};

let p = children => {
  {node: P, value: None, children};
};

let getNode = htmlNode => {
  htmlNode.node;
};

let node_as_string = node => {
  switch (node) {
  | P => "p"
  | Text => ""
  };
};

let get_value = html => {
  switch (html.value) {
  | None => ""
  | Some(value) => value
  };
};

let rec as_string = html => {
  let render_html_children = children => {
    List.fold_right(
      (htmlC, htmlS) => htmlS ++ as_string(htmlC),
      children,
      "",
    );
  };

  switch (getNode(html)) {
  | P => "<p>" ++ render_html_children(html.children) ++ "</p>"
  | Text => get_value(html)
  };
};