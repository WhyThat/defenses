let component = ReasonReact.statelessComponent("Planet");
[%mui.withStyles
  "StyledExample"({root: ReactDOMRe.Style.make(~textAlign="right", ())})
];
let make =
    (
      ~gauss,
      ~heavyLaser,
      ~ion,
      ~lightLaser,
      ~name,
      ~plasma,
      ~rocket,
      ~onDelete,
      _children,
    ) => {
  ...component,
  render: _self =>
    MaterialUi.(
      <StyledExample
        render={
          classes =>
            <Grid key=name item=true>
              <Card>
                <CardHeader
                  action={
                    <IconButton onClick={_event => onDelete()}>
                      {ReasonReact.string("X")}
                    </IconButton>
                  }
                  title={ReasonReact.string({j|$name|j})}
                />
                <CardContent>
                  <FormGroup>
                    <InputLabel>
                      {ReasonReact.string("Lanceur de missile")}
                      <Input
                        className={classes.root}
                        type_="number"
                        onChange={_ => Js.log("Lanceur de missile")}
                        placeholder="Lanceur de missile"
                        error=false
                        defaultValue={`Int(rocket)}
                      />
                    </InputLabel>
                    <InputLabel>
                      {ReasonReact.string("Laser leger")}
                      <Input
                        className={classes.root}
                        type_="number"
                        onChange={_ => Js.log("Laser leger")}
                        placeholder="Laser leger"
                        error=false
                        defaultValue={`Int(lightLaser)}
                      />
                    </InputLabel>
                    <InputLabel>
                      {ReasonReact.string("Laser Lourd")}
                      <Input
                        className={classes.root}
                        type_="number"
                        onChange={_ => Js.log("Laser lourd")}
                        placeholder="Laser lourd"
                        error=false
                        defaultValue={`Int(heavyLaser)}
                      />
                    </InputLabel>
                    <InputLabel>
                      {ReasonReact.string("Gauss")}
                      <Input
                        className={classes.root}
                        type_="number"
                        onChange={_ => Js.log("Gauss")}
                        placeholder="Gauss"
                        error=false
                        defaultValue={`Int(gauss)}
                      />
                    </InputLabel>
                    <InputLabel>
                      {ReasonReact.string("ion")}
                      <Input
                        className={classes.root}
                        type_="number"
                        onChange={_ => Js.log("ion")}
                        placeholder="ion"
                        error=false
                        defaultValue={`Int(ion)}
                      />
                    </InputLabel>
                    <InputLabel>
                      {ReasonReact.string("plasma")}
                      <Input
                        className={classes.root}
                        type_="number"
                        onChange={_ => Js.log("plasma")}
                        placeholder="Laser lourd"
                        error=false
                        defaultValue={`Int(plasma)}
                      />
                    </InputLabel>
                  </FormGroup>
                </CardContent>
              </Card>
            </Grid>
        }
      />
    ),
};
