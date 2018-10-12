module StateConfig = {
  type state = string;
};
module State = ReContainers.WithState.Make(StateConfig);

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => {
    let%Epitath emailState = children =>
      <State initialState=""> ...children </State>;

    <div>
      <h1> {ReasonReact.string("Meet Epitath")} </h1>
      <label> {ReasonReact.string("Email")} </label>
      <input
        onChange={
          event =>
            emailState.send(Set(ReactEvent.Form.target(event)##value))
        }
      />
      <p> {ReasonReact.string(emailState.state)} </p>
      {
        /* Combine as many as you want. Use even in the middle of JSX! */

        let%Epitath passwordState = children =>
          <State initialState=""> ...children </State>;

        <>
          <label> {ReasonReact.string("Password")} </label>
          <input
            onChange={
              event =>
                passwordState.send(
                  Set(ReactEvent.Form.target(event)##value),
                )
            }
          />
          <p> {ReasonReact.string(passwordState.state)} </p>
        </>;
      }
    </div>;
  },
};
