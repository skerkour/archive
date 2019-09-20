<?php


class Route
{
  public $method;
  public $pattern;
  public $handler = array();

  function __construct($method, $pattern, $handler) {
    $this->method = $method;
    $this->pattern = $pattern;
    array_push($this->handler, $handler);
  }

}

class Router
{
  private $routes = array();
  private $middlewares = array();

  function process_request($req, $res) {
    $this->execute_before_middlewares($req, $res);

    foreach ($this->routes as $route) {
      if (preg_match($route->pattern, $req->path)
        && $req->method == $route->method) {
          $route->handler[0]($req, $res);
          $this->execute_after_middlewares($req, $res);
          return true;
      }
    }

    $this->execute_after_middlewares($req, $res);
    return false;
  }

  private function execute_before_middlewares($req, $res) {
    foreach ($this->middlewares as $middleware) {
      $middleware->before_handler($req, $res);
    }

  }
  
  private function execute_after_middlewares($req, $res) {
    foreach ($this->middlewares as $middleware) {
      $middleware->after_handler($req);
    }
  }

  public function route($method, $route_pattern, $handler) {
    $route = new Route($method, $route_pattern, $handler);
    array_push($this->routes, $route);
  }

  public function get($route_pattern, $handler) {
    $this->set_route("GET", $route_pattern, $handler);
  }

  public function post($route_pattern, $handler) {
    $this->set_route("POST", $route_pattern, $handler);
  }
  
  public function put($route_pattern, $handler) {
    $this->set_route("PUT", $route_pattern, $handler);
  }
  
  public function delete($route_pattern, $handler) {
    $this->set_route("DELETE", $route_pattern, $handler);
  }

  private function set_route($method, $pattern, $handler) {
    $route = new Route($method, $pattern, $handler);
    array_push($this->routes, $route);
  }

}

?>
