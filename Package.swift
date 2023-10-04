// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.
import PackageDescription

let package = Package(
    name: "CmpSdk",
    platforms: [
        .iOS(.v12) // or the appropriate platform
    ],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "CmpSdk",
            targets: ["CmpSdk"]),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(
            name: "CmpSdk",
            path: "CmpSdk.xcframework"
        )
    ]
)
