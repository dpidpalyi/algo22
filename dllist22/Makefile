DEFAULT_GOAL: test

.PHONY: fmt vet test cover

fmt:
	go fmt ./...

vet: fmt
	go vet ./...

test: vet
	go test ./... -v --cover

cover: 
	go test ./... -v --cover -coverprofile=coverage.out
	go tool cover -html=coverage.out
