type ressources = {
  metal: int,
  cristal: int,
  deuterium: int,
  base: int,
};
type defensesModel = {
  rocket: ressources,
  lightLaser: ressources,
  heavyLaser: ressources,
  gauss: ressources,
  ion: ressources,
  plasma: ressources,
};

type defenses = {
  rocket: int,
  lightLaser: int,
  heavyLaser: int,
  gauss: int,
  ion: int,
  plasma: int,
};

type planet = {
  name: string,
  id: string,
  defenses,
};
