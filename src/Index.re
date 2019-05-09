let reducer = (action, _state) =>
  switch (action) {
  | "2" => ""
  | _ => "2"
  };

ReactDOMRe.renderToElementWithId(<Layout />, "root");
