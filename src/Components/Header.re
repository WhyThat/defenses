let component = ReasonReact.statelessComponent("Header");

[%mui.withStyles
  "StyledExample"({
    root:
      ReactDOMRe.Style.make(
        ~color="white",
        ~flexGrow="1",
        ~marginBottom="10px",
        (),
      ),
  })
];
/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = _children => {
  /* spread the other default fields of component here and override a few */
  ...component,
  render: _self =>
    MaterialUi.(
      <StyledExample
        render={
          classes =>
            <AppBar position=`Static className={classes.root}>
              <Toolbar>
                <IconButton color=`Inherit />
                <Typography variant=`Title color=`Inherit>
                  {ReasonReact.string("OgameDefenses")}
                </Typography>
              </Toolbar>
            </AppBar>
        }
      />
    ),
};