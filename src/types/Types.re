type ressources = {
  metal: int,
  cristal: int,
  deuterium: int,
  base: int,
};

type defenses('a) = {
  rocket: 'a,
  lightLaser: 'a,
  heavyLaser: 'a,
  gauss: 'a,
  ion: 'a,
  plasma: 'a,
};

type defensesModel = defenses(ressources);
type planet = {
  name: string,
  id: string,
  defenses: defenses(int),
};
