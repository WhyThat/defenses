let component = ReasonReact.statelessComponent("Entry");

let make = children => {
  /* spread the other default fields of component here and override a few */
  ...component,
  render: _self =>
    MaterialUi.(
      <Grid container=true spacing=V8 alignContent=`Space_Between>
        children
      </Grid>
    ),
};