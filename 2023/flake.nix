{
  description = "A basic flake with a shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          packages = [];
          nativeBuildInputs = [
            (pkgs.python3.withPackages (python-pkgs: [
            ]))
          ];
          buildInputs = [ ];
          shellHook = ''
            nix flake update
          '';
        };
      });
}
