import Koa from 'koa'
import { koaBody } from 'koa-body'
import Router from 'koa-router'
import serverless from 'serverless-http'

import routes from './routes.js'

const app = new Koa()
const router = new Router()

app.use(koaBody())

router.use('/.netlify/functions/api', routes)

app.use(router.routes())

export const handler = serverless(app)
export default app


