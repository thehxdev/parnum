{
    description = "Nix Flake-Based development environment for C.";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixos-23.11";
    };

    outputs = { self, nixpkgs, ... }: let
        system = "x86_64-linux";
    in {
        devShells."${system}".default = let
            pkgs = import nixpkgs { inherit system; };
        in pkgs.mkShell {
            packages = with pkgs; [
                # compiler and `make`
                gcc
                gnumake

                # debugging stuff
                gdb
                valgrind

                # language server
                ccls
            ];

            # shellHook = ''
            # '';
        };
    };
}
