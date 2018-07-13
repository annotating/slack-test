/* reference
https://github.com/reasonml-community/reason-react-example/blob/master/src/todomvc/TodoItem.re
 */

type state = {
  text: string,
  textFieldRef: ref(option(Dom.element))
};

let setTextFieldRef = (r, {ReasonReact.state}) =>
  state.textFieldRef := Js.Nullable.toOption(r);

type action =
| KeyDown(int)
| Change(string);

let onSave(value) = {
    ReasonReact.Router.push(value);
}

let onSubmit = state =>
    switch (String.trim(state.text)) {
    | nonEmptyValue =>
        ReasonReact.UpdateWithSideEffects(
            {...state, text: ""},
            (_self => onSave(nonEmptyValue)),
        )
};

let component = ReasonReact.reducerComponent("TextInput");

let make = (_children) => {
    ...component,
    initialState: () => {
      text: "",
      textFieldRef: ref(None),
    },
    reducer: action =>
      switch (action) {
      | KeyDown(13) => onSubmit
      | Change(text) => 
        state => ReasonReact.Update({...state, text})
      | KeyDown(_) => (_state => ReasonReact.NoUpdate)
    },
    render: ({state, handle, send}) => {
      <div>
        {ReasonReact.string("Go to URL: ")}
        <input
          placeholder = "Enter path"
          ref=(handle(setTextFieldRef))
          value=state.text
          onChange=(event => send(Change(
              ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
            ),
          ))
          onKeyDown=(event => send(KeyDown(ReactEventRe.Keyboard.which(event))))
        />
      </div>
    }
}