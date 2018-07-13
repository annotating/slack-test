[%bs.raw {|require('./App.css')|}];

type route =
  | Page1(string)
  | Page2(string);

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) => {
    let stringPath = List.fold_left((a,b)=>(a++"/"++b), "", url.path);
    Js.log(stringPath);
    switch url.path {
    | ["\#", "page1"] => Page1("page1")
    | ["\#", "page2"] => Page2("page2")
    | _ => Page1("no match. you entered: " ++ stringPath)
    };
  }

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: Page1("home")},
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url => {
          self.send(ChangeRoute(url |> mapUrlToRoute))
        }),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
  render: self =>
    switch (self.state.route) {
      | Page1(message) => <SimpleExample message />
      | Page2(msg) => <CountButton greeting=msg/>
      }, 
    /* <div className="App"> */
      /* <p className="App-intro">
        (ReasonReact.string("To get started, edit"))
        <code> (ReasonReact.string(" src/App.re ")) </code>
        (ReasonReact.string("and save to reload."))
      </p> */

      /* <div>
        <SimpleExample message="SimpleExample"/>
      </div>
      <div>
        <CountButton greeting="Greeting"/>
      </div> */
    /* </div> */
};
