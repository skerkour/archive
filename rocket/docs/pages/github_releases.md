# GitHub releases

## Fields

| Field             | Type |Default Value | Description |
| ------------------| ---- | ------------ | ----------- |
| `name` | `string` | **$ROCKET_LAST_TAG** | The release's name |
| `body` | `string` | `""` | The release's body | 
| `prerelease` | `bool` | `false` | Identify the release as a prerelease |
| `repo` | `string` | **$ROCKET_GIT_REPO** | The GitHub repo to release |
| `api_key` | `string` | **$GITHUB_API_KEY** | The required GitHub API key |
| `assets` | `[string]` | `[]` | The assets to upload following the [`go` glob pattern](https://golang.org/pkg/path/filepath/#Match) |
| `tag` | `string` | **$ROCKET_LAST_TAG** | The `git` tag to release |
| `base_url` | `string` | **$GITHUB_BASE_URL** | Used to release to GitHub Enterprise |
| `upload_url` | `string` | **base_url** | Used to release to GitHub Enterprise, if set **`base_url` should be set, error otherwise** |


## Example

```san
# .rocket.san
github_releases = {
  api_key = "$GITHUB_TOKEN"
  assets = [
    "dist/*.zip",
    "dist/rocket_*_sha512sums.txt",
  ]
}
```
