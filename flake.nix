{
  description = "C++ environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    inputs@{ flake-parts, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      # This is the list of architectures that work with this project
      systems = [
        "x86_64-linux"
        "aarch64-linux"
        "aarch64-darwin"
        "x86_64-darwin"
      ];
      perSystem =
        {
          config,
          self',
          inputs',
          pkgs,
          system,
          ...
        }:
        {

          devShells.default = pkgs.mkShell {
            packages = with pkgs; [
              gtest
              cmake
              zip
              yaml-cpp
              qtcreator
              # libsForQt5.full
              qt6.full
              qt6.qtbase
              qt6.qtdeclarative
              gnumake
              gcc
              gdb
              just
              entr
              libssh
            ];
          };
        };
    };
}
