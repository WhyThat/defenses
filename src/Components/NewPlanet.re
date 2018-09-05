type state = {newPlanetName: string};

type actions =
  | UpdatePlanetName(string);

let component = ReasonReact.reducerComponent("NewPlanet");

let make = (~onAddPlanet, _children) => {
  ...component,
  reducer: (action: actions, _state) =>
    switch (action) {
    | UpdatePlanetName(newName) =>
      ReasonReact.Update({newPlanetName: newName})
    },
  initialState: () => {newPlanetName: ""},
  render: ({state, send}) =>
    MaterialUi.(
      <Grid item=true>
        <Card>
          <CardContent>
            <Typography
              gutterBottom=true variant=`Headline component={`String("h2")}>
              {ReasonReact.string("Ajouter une nouvelle planete")}
            </Typography>
            <FormGroup>
              <Input
                placeholder="Nom de la planete"
                onKeyDown={
                  event =>
                    if (ReactEvent.Keyboard.keyCode(event) === 13) {
                      ReactEvent.Keyboard.preventDefault(event);
                      onAddPlanet(state.newPlanetName);
                    } else {
                      send(
                        UpdatePlanetName(
                          ReactEvent.Keyboard.target(event)##value,
                        ),
                      );
                    }
                }
              />
            </FormGroup>
          </CardContent>
        </Card>
      </Grid>
    ),
};
