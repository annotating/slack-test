let component = ReasonReact.statelessComponent("SimpleExample");

let handleClick = (_event, _self) => {
  Js.log("clicked!");
}

let make = (~message, _children) => {
  ...component,
  render: self =>
  <div>
    <button onClick={self.handle(handleClick)}>
      {ReasonReact.string(message)}
    </button>
    <GoTo/>
  </div>
};

