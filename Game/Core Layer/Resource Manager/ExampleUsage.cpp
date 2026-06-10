ResourceManager Resources;

Resources.Initialize();

AssetReference Skyline;

Skyline.Handle.ID = 1001;

Skyline.Type =
    EAssetType::Vehicle;

Skyline.Path =
    "Vehicles/SkylineR34.asset";

Skyline.bStreamable =
    true;

AssetHandle Handle =
    Resources.LoadAsset(
        Skyline
    );
