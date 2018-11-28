## bs-epitath demo

Read the article https://medium.com/astrocoders/render-props-composition-for-reasonml-is-here-b9c004ca9fcb

## Running

```
npm install
```

```
npm start
```


```reason
module StateConfig = {
  type state = string;
};
/* ReContainers is from https://github.com/Astrocoders/recontainers/ */
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
```
