open Belt;

[@bs.val] external unsafeJsonParse: string => 'a = "JSON.parse";

let localStorageNamespace = "ogame-defense";

let saveLocally = planet =>
  switch (Js.Json.stringifyAny(planet)) {
  | None => ()
  | Some(stringifiedPlanet) =>
    Dom.Storage.(
      localStorage |> setItem(localStorageNamespace, stringifiedPlanet)
    )
  };

let getPlanets = () =>
  switch (Dom.Storage.(localStorage |> getItem(localStorageNamespace))) {
  | None => []
  | Some(planet) => unsafeJsonParse(planet)
  };

type actions =
  | AddPlanet(string)
  | DeletePlanet(Types.planet);

let initialDefense: Types.defenses = {
  rocket: 0,
  lightLaser: 0,
  heavyLaser: 0,
  gauss: 0,
  ion: 0,
  plasma: 0,
};

type state = {planets: list(Types.planet)};

let component = ReasonReact.reducerComponent("Layout");

let make = _children => {
  ...component,
  reducer: (action, state) =>
    switch (action) {
    | AddPlanet(value) =>
      let planets =
        List.length(state.planets) < 9 ?
          state.planets
          @ [{defenses: initialDefense, name: value, id: "ponet"}] :
          state.planets;
      saveLocally(planets);
      ReasonReact.Update({planets: planets});
    | DeletePlanet(planet) =>
      let planets =
        List.keep(state.planets, candidate => candidate !== planet);
      ReasonReact.Update({planets: planets});
    },
  initialState: () => {planets: getPlanets()},
  render: ({state, send}) => {
    let handleAddPlanet = planetName => send(AddPlanet(planetName));
    let planets =
      List.map(state.planets, (planet: Types.planet) =>
        <Planet
          onDelete={() => send(DeletePlanet(planet))}
          key={planet.name}
          name={planet.name}
          rocket={planet.defenses.rocket}
          lightLaser={planet.defenses.lightLaser}
          heavyLaser={planet.defenses.heavyLaser}
          gauss={planet.defenses.gauss}
          ion={planet.defenses.ion}
          plasma={planet.defenses.plasma}
        />
      );
    <>
      <Header />
      <Entry>
        {ReasonReact.array(List.toArray(planets))}
        <NewPlanet onAddPlanet=handleAddPlanet />
      </Entry>
    </>;
  },
};
